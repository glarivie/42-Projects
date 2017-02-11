import 'dotenv/config';

import socketIo           from 'socket.io';
import http               from 'http';
import setupSocket        from './socket';


const server = http.createServer();
const io = socketIo(server);

io.on('connection', setupSocket);

server.listen(process.env.SERVER_PORT, () => {
  console.log(`[Express] Api is running on ${process.env.SERVER_PORT}`);
});
