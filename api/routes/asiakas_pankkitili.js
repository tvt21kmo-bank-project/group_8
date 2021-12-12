const express = require('express');
const router = express.Router();

const asiakas_pankkitili = require('../models/asiakas_pankkitili_model');

router.get('/:id?',
function(request, response)
{
    if(request.params.id)
    {
        asiakas_pankkitili.getById(request.params.id, function(err, dbResult)
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
        asiakas_pankkitili.getAll(function(err, dbResult)
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
    asiakas_pankkitili.add(request.body, function(err, dbResult)
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
    asiakas_pankkitili.delete(request.params.id, function(err, dbResult)
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
    asiakas_pankkitili.update(request.params.id, request.body, function(err, dbResult)
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