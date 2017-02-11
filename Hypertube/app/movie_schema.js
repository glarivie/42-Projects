var mongoose = require('mongoose'),
	Schema = mongoose.Schema;

var movieSchema = new Schema({
	title: { type: String, unique: true, required: true, dropDups: true },
	year:	{ type: Number, required: true },
	resolutions: [{
		resolution: { type: String, required: true },
		seeds:			{ type: Number, required: true },
		magnet:		 { type: String, required: true },
		source:		 { type: String, required: true },
		data:			 {
									name: String,
									length: Number,
									path: String,
									torrent_date: Date
		}
	}],
	rated: String,
	runtime: String,
	released: Date,
	genres: { type: [String], index: true },
	director: String,
	writers: [String],
	actors: [String],
	plot: String,
	poster: { type: String, required: true },
	imdb: {
		url: String,
		rating: { type: Number, required: true },
		votes: Number
	},
	comments: [{
		id: String,
		date: Date,
		text: String,
		user: {
			id : String,
			firstname: String,
			lastname: String,
			avatar: String
		}
	}]
});

movieSchema.statics.findByTitle = function (name, cb) {
	return this.find({ title: new RegExp('^'+name+'$', 'i') }, cb);
}

var Movie = mongoose.model('Movie', movieSchema);

module.exports = Movie;
