import _					from 'lodash';
import Player			from '../Player';
import Game				from '../Game';

/*
*		Triggered when a new user is connected.
*		We create a new user.
*		If the user wants to join an already existing
*		game, we just add the player to it.
*		Else, we setup a new game and we set the player
*		as moderator
*/

const auth = (data, users, socket, games) => {
  const { username, room } = data;
  const player = new Player(username, room, socket);
  users.push(player);
  const already = _.find(games, el => el.id === room);
  if (already) {
    already.addPlayer([player]);
  } else {
    games.push(new Game(room, player));
    player.setModerator();
  }
};

export default (users, socket, games) => (action) => {
	console.log(users, games);
  switch (action.type) {
    case 'server/auth':
      auth(action.data, users, socket, games);
      break;
    default:
  }
};
