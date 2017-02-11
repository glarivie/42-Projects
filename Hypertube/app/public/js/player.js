/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.js                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 16:49:11 by glarivie          #+#    #+#             */
/*   Updated: 2016/06/13 21:02:03 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var video = document.getElementById('video');
var mustBeAdd = true;
//var interval_id = setInterval(function() {
	video.load();
//}, 10000);

$.post('/api/movie/subtitles/get', {
	movieID : $('#video').data('id'),
	movieResolution : $('#video').data('resolution')
}).done(function(data) {
	if (data.state === 'success')
		track = document.createElement('track');
		track.kind = 'captions';
		track.srclang = $('#lang-choice').data('user-lang').toLowerCase();
		track.src = '/sub/sub.vtt';
		track.addEventListener('load', function() {
			this.mode = 'showing';
			video.textTracks[0].mode = 'showing';
		});
		video.appendChild(track);
	});

video.onloadedmetadata = function() {
	//clearInterval(interval_id);
	$('#metadata').removeClass('hidden');
	video.oncanplay = function() {
		$('#ready').removeClass('hidden');
		// console.log('video is ready to play.');
		video.play();
	};
};

video.addEventListener('ended', function() {
	var time = video.currentTime;
	//console.log(time);
	if (time < 3600) {
		video.load();
		video.currentTime = time;
	}
}, false);

$(document).ready(function() {
	$('small.date').each(function() {
		$(this).html($.format.prettyDate($(this).html()));
	});

	$.post('/api/movie/visit/add', { movieID : $('#video').data('id') })
		.done(function(data) {
			if (data.state === 'success')
				console.log('Movie added to you history');
		});
});

var state = {
	comment : "",
	id : $('#video').data('id')
};

$('.delete-comment').on({
	'mouseover' : function() {
		$(this).children('.fa').removeClass('fa-trash-o').addClass('fa-trash');
	},
	'mouseout' : function() {
		$(this).children('.fa').removeClass('fa-trash').addClass('fa-trash-o');
	},
	'click' : function() {
		var self = this;
		$.post('/api/comment/delete', {
			commentID : $(self).data('comment-id'),
			movieID : $('#video').data('id')
		}).done(function(data) {
			if (data.state === 'success') {
				$('#' + $(self).data('comment-id')).remove();
			} else {
				$('#' + $(self).data('comment-id') + ' .panel').removeClass('panel-default').addClass('panel-danger');
				$('#' + $(self).data('comment-id') + ' .comment-error').removeClass('hidden');
			}
		});
	}
});

$('#comment-area').on('input keyup change', function() {
	if ($(this).val().length > 0) {
		$('#comment-btn').removeAttr('disabled');
		state.comment = lib.protectEntry($(this).val());
	} else
		$('#comment-btn').attr('disabled', true);
});

$('#comment-btn').on('click', function() {
	var self = this;
	$(self).html('<i class="fa fa-refresh" aria-hidden="true"></i> Loading...');
	$(self).attr('disabled', true);

	$.post('/api/comment/new', state)
		.done(function(data) {
			if (data.state === 'success') {
				$('#comment-area').val('');
				$(self).html('<i class="fa fa-comment" aria-hidden="true"></i> Add my comment');
				$('#comments-list').prepend('<div class="col-md-12 comment-block" id="' + data.comment.id + '"><div class="avatar img-rounded img-responsive" style="background-image: url(' + data.comment.user.avatar + ');"></div><div class="panel panel-default content"><div class="panel-heading username"><strong><a href="/user/' + data.comment.user.id + '">' + data.comment.user.firstname + ' ' + data.comment.user.lastname + '</a></strong> <small class="text-muted date">' + $.format.prettyDate(data.comment.date) + '</small></div><div class="panel-body text"><em>' + data.comment.text + '</em></div></div></div>');
			}
		});
});
