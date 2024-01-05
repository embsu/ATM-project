var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const dotenv = require('dotenv');
const jwt = require('jsonwebtoken');


var indexRouter = require('./routes/index');

var asiakasRouter = require('./routes/asiakas');
var creditRouter = require('./routes/credit');
var debitRouter = require('./routes/debit');
var korttiRouter = require('./routes/kortti');
var creditTapahtumatRouter = require('./routes/creditTapahtumat');
var debitTapahtumatRouter = require('./routes/debitTapahtumat');
var loginRouter = require('./routes/login');


var app = express();
dotenv.config();


app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

//suojaamattomat endpointit
app.use('/', indexRouter);
app.use('/login', loginRouter);
//suojatut endpointit
app.use('/kortti', korttiRouter);
app.use('/asiakas', asiakasRouter);
app.use('/credit', creditRouter);
app.use('/debit', debitRouter);
app.use('/creditTapahtumat', creditTapahtumatRouter);
app.use('/debitTapahtumat', debitTapahtumatRouter);




function authenticateToken(req, res, next) {
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]

    console.log("token = "+token);
    if (token == null) return res.sendStatus(401)
  
    jwt.verify(token, process.env.MY_TOKEN, (err, user) => {
      console.log(err)
  
      if (err) return res.sendStatus(403)
  
      req.user = user
  
      next()
    })
  }

  module.exports = app;