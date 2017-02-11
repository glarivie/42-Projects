(function () {
	var skip = 0,
		limit = 18,
		sort = 'year',
		order = 'desc',
		notDetected = true;



	function getMovies(skip, limit) {
		// console.log('limit', limit, 'skip', skip);
		$.post('/api/library/movies/get', {
			skip : skip,
			limit : limit,
			sort : sort,
			order : order
		}).done(function(data) {
			if (data.state === 'success') {
				$.each(data.movies, function(index, movie) {
					$('#getMovies').append('<div class="col-md-4 col-sm-6 col-xs-12"><div class="movie" id="' + movie._id + '"><div class="poster" style="background-image: url(' + movie.poster + ');"><div class="resolutions hidden"></div></div><div class="movie-infos"><h4><a href="/player/html5/' + movie._id + '/' + movie.resolutions[0].resolution + '">' + movie.title + '</a> (' + movie.year + ')</h4><small class="movie-basics text-muted"><span class="rated">' + movie.rated + '</span>' + movie.runtime + ' - ' + movie.genres + '</small><p class="imdb-rating"><strong>IMDB Rating: ' + movie.imdb.rating + '</strong>/10 (' + movie.imdb.votes + ')</p><p class="plot"><em>' + movie.plot + '</em></p><p class="director"><strong>Director: </strong>' + movie.director + '</p><p class="stars"><strong>Stars: </strong>' + movie.actors + '</p></div></div></div>');

					$.each(movie.resolutions, function(index, resolution) {
						$('#getMovies #' + movie._id + ' .resolutions').append('<a href="/player/html5/' + movie._id + '/' + resolution.resolution + '" type="button" class="btn btn-resolution btn-sm"><i class="fa fa-play-circle" aria-hidden="true"></i> <strong>' + resolution.resolution + '</strong> <em>(' + resolution.seeds + ')</em></a>');
					});
				});

				$('.poster').on({
					'mouseover' : function() {
						$(this).children('.resolutions').removeClass('hidden');
					},
					'mouseout' : function() {
						$(this).children('.resolutions').addClass('hidden');
					}
				});
			} else {
				console.log('No more movies found, infinite scroll stop.');
				$(window).off('scroll');
				notDetected = false;
			}
		});
	}

	$(document).ready(function() {
		getMovies(skip, limit);
		skip += 18;
	});

	$('#filter-a-z').on('click', function() {
		$('#filters > button').each(function() {
			$(this).removeClass('btn-primary').addClass('btn-default');
		});
		$(this).removeClass('btn-default').addClass('btn-primary');
		sort = 'title';
		skip = 0;
		order = 'asc';
		$('#getMovies').empty();
		getMovies(skip, limit);
		skip += 18;
	});

	$('#filter-z-a').on('click', function() {
		$('#filters > button').each(function() {
			$(this).removeClass('btn-primary').addClass('btn-default');
		});
		$(this).removeClass('btn-default').addClass('btn-primary');
		sort = 'title';
		skip = 0;
		order = 'desc';
		$('#getMovies').empty();
		getMovies(skip, limit);
		skip += 18;
	});

	$('#filter-note').on('click', function() {
		$('#filters > button').each(function() {
			$(this).removeClass('btn-primary').addClass('btn-default');
		});
		$(this).removeClass('btn-default').addClass('btn-primary');
		sort = 'imdb.rating';
		skip = 0;
		order = 'desc';
		$('#getMovies').empty();
		getMovies(skip, limit);
		skip += 18;
	});

	$('#filter-year').on('click', function() {
		$('#filters > button').each(function() {
			$(this).removeClass('btn-primary').addClass('btn-default');
		});
		$(this).removeClass('btn-default').addClass('btn-primary');
		sort = 'year';
		skip = 0;
		order = 'desc';
		$('#getMovies').empty();
		getMovies(skip, limit);
		skip += 18;
	});

	$(window).on('scroll', function() {
		if($(window).scrollTop() + $(window).height() > $(document).height() - .001 * $(document).height() && notDetected) {
			notDetected = false;
			getMovies(skip, limit);
			skip += 18;
			notDetected = true;
		}
	});

})();
