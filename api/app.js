var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const helmet = require('helmet');
const cors = require('cors');
var app = express();
const dotenv = require('dotenv');
const mysql = require('mysql');
const basicAuth = require('express-basic-auth');

dotenv.config();
app.use(basicAuth( { authorizer: myAuthorizer, authorizeAsync:true, } ))

function myAuthorizer(username, password, cb){
    if(username===process.env.authUser && password===process.env.authPass){
        return cb(null, true);
    }
    else{
        return cb(null, false);
    }
}

app.use(helmet());
app.use(cors());

var pankkikorttiRouter = require('./routes/pankkikortti');
var asiakasRouter = require('./routes/asiakas');
var asiakas_pankkitiliRouter = require('./routes/asiakas_pankkitili');
var pankkitiliRouter = require('./routes/pankkitili');
var tapahtumatRouter = require('./routes/tapahtumat');
var loginRouter = require('./routes/login');
var pankkiRouter = require('./routes/pankki');

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/pankkikortti', pankkikorttiRouter);
app.use('/asiakas', asiakasRouter);
app.use('/asiakas_pankkitili', asiakas_pankkitiliRouter);
app.use('/pankkitili', pankkitiliRouter);
app.use('/tapahtumat', tapahtumatRouter);
app.use('/login', loginRouter);
app.use('/pankki', pankkiRouter);

module.exports = app;
