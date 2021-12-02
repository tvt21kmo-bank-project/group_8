const express = require('express');
const router = express.Router();
const pankki = require('../models/pankki_model');

router.post('/kate', function(request, response){
    pankki.kate(request.body, function(err, dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.send(dbResult[0]);
        }
    });
});

router.post('/saldo', function(request, response){
    pankki.saldo(request.body, function(err, dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.json(dbResult[0]);
        }
    });
});

router.post('/tapahtumat', function(request, response){
    pankki.tapahtumat(request.body, function(err, dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.send(dbResult[0]);
        }
    });
});

router.post('/nosto', function(request, response){
    pankki.nosto(request.body, function(err, count){
        if(err){
            response.json(err);
        } 
        else{
            response.json(count);
        }
    });

});

router.post('/talletus', function(request, response){
    pankki.talletus(request.body, function(err, count){
        if(err){
            response.json(err);
        }
        else{
            response.json(count);
        }
    });
});


module.exports = router;