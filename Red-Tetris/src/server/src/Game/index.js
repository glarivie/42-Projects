import _      from 'lodash';

export default class Game {
  constructor(gameID, moderator) {
    this.moderator	= moderator;
    this.players		= [moderator];
    this.id					= gameID;
  }

  addPlayer(newPlayer) {
    const alreadyIn = _.find(this.players,
      player => player.id === newPlayer.id);
    if (alreadyIn) {
      newPlayer.emit('error message', 'user is already in the game');
			return false;
    }
    this.players.push(newPlayer);
    newPlayer.emit('created', 'user has been successfully created');
		return true;
  }

  removePlayer(toRemove) {
    this.players = _.remove(this.players,
      player => player.id === toRemove.id,
    );
    if (this.players[0]) {
      this.moderator = this.players[0];
      this.players[0].setModerator();
    }
  }

}
