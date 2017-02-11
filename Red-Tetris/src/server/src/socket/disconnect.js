import _        from 'lodash';

/*
*     Triggered when the user is disconnected.
*     We remove the user from the users list
*/
export default (users, socket, games) => () => {
  const player = _.find(users, el => el.id === socket.id);
  if (!player) return false;
  const currentGame = _.find(games, games.id === player.roomID);
  if (currentGame) currentGame.removePlayer(player);
  users = _.remove(users, el => el.id === socket.id);
  return true;
};
