import action       from './action';
import disconnect		from './disconnect';

const users = [];
const games = [];

export default (socket) => {
  socket.on('action', action(users, socket, games));
  socket.on('disconnect', disconnect(users, socket, games));
};
