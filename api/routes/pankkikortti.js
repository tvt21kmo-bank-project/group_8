const express = require('express');
const router = express.Router();
const pankkikortti = require('../models/pankkikortti_model');

router.get('/:id?', function(request, response){
    if (request.params.id){
        pankkikortti.getById(request.params.id, function(err, dbResult){
            if(err){
                response.json(err);
            }
            else{
                response.json(dbResult);
            }
        });
    }
    else{
        pankkikortti.get(function(err, dbResult){
            if(err){
                response.json(err);
            }
            else{
                response.json(dbResult);
            }
        });
    }
});

router.post('/', function(request, response){
    pankkikortti.add(request.body, function(err, count){
        if(err){
            response.json(err);
        }
        else{
            response.json(count);
        }
    });
});

router.post('/pin', function(request, response){
    pankkikortti.pin(request.body, function(err, dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.json(dbResult);
        }
    });
});

router.get('/poista/:korttinumero', function(request, response){
    pankkikortti.delete(request.params.korttinumero, function(err, count){
        if(err){
            response.json(err);
        }
        else{
            response.json(count);
        }
    });
});

router.put('/:korttinumero', function(request, response){
    pankkikortti.update(request.params.korttinumero, request.body, function(err, dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.json(dbResult);
        }
    });
});

module.exports = router;