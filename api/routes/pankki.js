const express = require('express');
const router = express.Router();
const pankki = require('../models/pankki_model');

router.post('/credit_tilisiirto', function(request, response){
    pankki.credit_tilisiirto(request.body, function(err, dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.send(dbResult[0]);
        }
    });
});

router.post('/credit_to_debit', function(request, response){
    pankki.credit_to_debit(request.body, function(err, dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.json(dbResult[0]);
        }
    });
});

router.post('/debit_tilisiirto', function(request, response){
    pankki.debit_tilisiirto(request.body, function(err, dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.send(dbResult[0]);
        }
    });
});

router.post('/debit_to_credit', function(request, response){
    pankki.debit_to_credit(request.body, function(err, count){
        if(err){
            response.json(err);
        } 
        else{
            response.json(count);
        }
    });

});

router.post('/otto', function(request, response){
    pankki.otto(request.body, function(err, count){
        if(err){
            response.json(err);
        }
        else{
            response.json(count);
        }
    });
});

router.post('/otto_transfer', function(request, response){
    pankki.otto_transfer(request.body, function(err, count){
        if(err){
            response.json(err);
        }
        else{
            response.json(count);
        }
    });
});


router.post('/saldo_katsaus', function(request, response){
    pankki.saldo_katsaus(request.body, function(err, count){
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

router.post('/talletus_transfer', function(request, response){
    pankki.talletus_transfer(request.body, function(err, count){
        if(err){
            response.json(err);
        }
        else{
            response.json(count);
        }
    });
});

router.post('/tilitapahtuma_katsaus', function(request, response){
    pankki.tilitapahtuma_katsaus(request.body, function(err, count){
        if(err){
            response.json(err);
        }
        else{
            response.json(count);
        }
    });
});


module.exports = router;