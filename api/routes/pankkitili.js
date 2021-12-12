const express = require('express');
const router = express.Router();
const pankkitili = require('../models/pankkitili_model');

router.get('/:id?',
function(request, response)
{
    if(request.params.id)
    {
        pankkitili.getById(request.params.id, function(err, dbResult)
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
        pankkitili.getAll(function(err, dbResult)
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
    pankkitili.add(request.body, function(err, dbResult)
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
                console.log("Tili lisatty");
            }
        }
    });
});

router.delete('/:id',
function(request, response)
{
    pankkitili.delete(request.params.id, function(err, dbResult)
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
                console.log("Tili poistettu");
            }
        }
    });
});

router.put('/:id',
function(request, response)
{
    pankkitili.update(request.params.id, request.body, function(err, dbResult)
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
                console.log("Tili paivitetty");
            }
        }
    });
});

module.exports = router;