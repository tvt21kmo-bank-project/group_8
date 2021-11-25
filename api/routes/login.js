const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');

router.get('/:id', function(request, response){
  if (request.params.id){
    login.getById(request.params.id, function(err, dbResult){
          if(err){
              response.json(err);
          }
          else{
              response.json(dbResult);
          }
      });
  }
});



router.post('/', function(request, response) {
    if(request.body.korttinumero && request.body.pin){
      const korttinumero = request.body.korttinumero;
      const pin = request.body.pin;
        login.checkPassword(korttinumero, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) {
              bcrypt.compare(pin,dbResult[0].pin, function(err,compareResult) {
                if(compareResult) {
                  console.log("Pass");
                  response.send(true);
                }
                else {
                    console.log("Pin väärin");
                    response.send(false);
                }			
              }
              );
            }
            else{
              console.log("Korttia ei löydy");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("username or pin missing");
      response.send(false);
    }
  }
);

module.exports=router;