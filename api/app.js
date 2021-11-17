var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const helmet = require('helmet');
const cors = require('cors');
var app = express();

const db = require('./database');
const basicAuth = require('express-basic-auth');
const bcrypt = require('bcryptjs');

app.use(helmet());
app.use(cors());
//app.use(basicAuth({authorizer: myAuthorizer, authorizeAsync:true, }))

// const dotenv = require('dotenv');
// dotenv.config();

var bankRouter = require('./routes/bank');
var loginRouter = require('./routes/login');
const { response } = require('express');

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({extended: false}));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/login', loginRouter);
app.use('/bank', bankRouter);


module.exports = app;