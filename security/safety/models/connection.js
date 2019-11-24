const mysql = require('mysql');
exports.getConnection = function(){
	let connection = mysql.createConnection({
		host: '127.0.0.1',
		database: 'safety',
		user: 'root',
		password: 'abc123'
	});
	connection.connect();
	return connection;
};
