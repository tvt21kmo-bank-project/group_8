const express = require('express');
const router = express.Router();
const asiakas_pankkitili = require('../models/asiakas_pankkitili_model');

router.get('/:id?', function(request, response){
    if (request.params.id){
        asiakas_pankkitili.getById(request.params.id, function(err, dbResult){
            if(err){
                response.json(err);
            }
            else{
                response.json(dbResult);
            }
        });
    }
    else{
        asiakas_pankkitili.getAll(function(err, dbResult){
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
    asiakas_pankkitili.add(request.body, function(err, count){
        if(err){
            response.json(err);
        }
        else{
            response.json(count);
        }
    });
});

router.delete('/:id', function(request, response){
    asiakas_pankkitili.delete(request.params.id, function(err, count){
        if(err){
            response.json(err);
        }
        else{
            response.json(count);
        }
    });
});

router.put('/:id', function(request, response){
    asiakas_pankkitili.update(request.params.id, request.body, function(err, dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.json(dbResult);
        }
    });
});

module.exports = router;