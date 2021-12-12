const express = require('express');
const router = express.Router();

const asiakas = require('../models/asiakas_model');

router.get('/:id?',
function(request, response)
{
    if(request.params.id)
    {
        asiakas.getById(request.params.id, function(err, dbResult)
        {
            if(err)
            {
                response.json(err);
            } 
            else
            {
                response.json(dbResult);
            }
        });
    }
    else
    {
        asiakas.getAll(function(err, dbResult)
        {
            if(err)
            {
                response.json(err);
            }
            else
            {
            response.json(dbResult);
            }
        });
    }
});

router.post('/',
function(request, response)
{
    asiakas.add(request.body, function(err, dbResult)
    {
        if(err)
        {
            response.json(err);
        }
        else
        {
            response.json(dbResult.affectedRows);
            if (dbResult.affectedRows == 0)
            {
                console.log("Jotain meni vikaan");                
            }
            else
            {
                console.log("Asiakas lisatty");
            }
        }
    });
});

router.delete('/:id',
function(request, response)
{
    asiakas.delete(request.params.id, function(err, dbResult)
    {
        if(err)
        {
            response.json(err);
        }
        else
        {
            response.json(dbResult.affectedRows);
            if (dbResult.affectedRows == 0)
            {
                console.log("Jotain meni vikaan");                
            }
            else
            {
                console.log("Asiakas poistettu");
            }
        }
    });
});

router.put('/:id',
function(request, response)
{
    asiakas.update(request.params.id, request.body, function(err, dbResult)
    {
        if(err)
        {
            response.json(err);
        }
        else
        {
            response.json(dbResult.affectedRows);
            if (dbResult.affectedRows == 0)
            {
                console.log("Jotain meni vikaan");                
            }
            else
            {
                console.log("Asiakas paivitetty");
            }
        }
    });
});

module.exports = router;