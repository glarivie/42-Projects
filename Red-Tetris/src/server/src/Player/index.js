export default class Player {
  constructor(username, roomID, socket) {
    this.username			= username;
    this.id						= socket.id;
    this.roomID				= roomID;
    this.emit					= socket.emit;
    this.isModerator	= false;
  }

  setModerator() {
		this.isModerator = true;
  }
}
