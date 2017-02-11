$('#notifications').hide();
var open = false;

$('#notifs').on('click', function() {
	if (!open) {
		$('#notifications').slideDown(300);
		open = true;
	} else if (open) {
		$('#notifications').slideUp(300);
		open = false;
	}
});

$('#close-notifs').on('click', function() {
	$('#notifications').slideUp(300);
	open = false;
});

$(document).ready(function() {
	getNotifications();
});

setInterval(function() {
	getNotifications();
}, 10000);


function renderNotif(type, date, id, name) {
	var icon = 'bullhorn';
	name = name ? name : 'Someone';
	if (type === 'visit') { icon = 'eye-open'; }
	if (type === 'like') { icon = 'heart'; type = 'lik'; }
	if (type === 'report') { icon = 'trash'; }
	if (type === 'dislike') { icon = 'flash'; type = 'dislik'; }
	if (type === 'message') { icon = 'send'; type = 'messag'; }
	if (type === 'match') { icon = 'fire'; }
	return ('<li class="one-notif"><span class="icon-notif glyphicon glyphicon-' + icon + '" aria-hidden="true"></span><ul class="infos-notifs"><li><a href="/user/' + id + '">' + name + '</a> <strong>' + type + 'ed</strong> your profile.</li><li class="text-muted"><small><span class="glyphicon glyphicon-calendar" aria-hidden="true"></span> ' + $.format.prettyDate(date) + '</small></li></ul></li>');
}

function getNotifications() {
	$.get('/notifications')
		.done(function(data) {
			if (data.done === 'success') {
				$('#notifications .panel-body ul#notif-tab').empty();
				$.each(data.notifs, function(index, n) {
					$('#notifications .panel-body ul#notif-tab')
						.append(renderNotif(n.type, n.date, n.userID, n.firstname));
				});
				if (data.notifs && data.notifs.length > 0) {
					$('#notifs-badge').html(data.notifs.length);
					$('#notifs .glyphicon-bell').css('color', '#f0ad4e');
				}
			} else
				console.log('0 notification(s) found in database');
		}).fail(function() {
			console.log('0 notification(s) found in database');
		});
}
