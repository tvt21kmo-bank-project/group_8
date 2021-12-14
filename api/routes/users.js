const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');

const users = require('../models/users_model');

router.get('/:id?',
function(request, response)
{
    if(request.params.id)
    {
        users.getById(request.params.id, function(err, dbResult)
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
        users.getAll(function(err, dbResult)
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
    users.add(request.body, function(err, dbResult)
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
                console.log("Käyttäjä lisatty");
            }
        }
    });
});

router.delete('/:id',
function(request, response)
{
    users.delete(request.params.id, function(err, dbResult)
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
                console.log("Käyttäjä poistettu");
            }
        }
    });
});

router.put('/:id',
function(request, response)
{
    users.update(request.params.id, request.body, function(err, dbResult)
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
                console.log("Käyttäjä paivitetty");
            }
        }
    });
});

module.exports = router;