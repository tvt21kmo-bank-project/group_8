const express = require('express');
const router = express.Router();
const user = require('../models/user_model');

router.get('/:id?',
function(request, response)
{
    if(request.params.id)
    {
        user.getById(request.params.id, function(err, dbResult)
        {
            if(err)
            {
                response.json(err);
                console.log(err);
            }
            else
            {
                response.send(dbResult[0].username);
                console.log(dbResult[0].username);
            }
        });
    }
    else
    {
        user.get(function(err, dbResult)
        {
            if(err)
            {
                response.json(err);
                console.log('get ' + err);
            }
            else
            {
                response.json(dbResult);
                console.log(dbResult);
            }
        });
    }
});

router.post('/',
function(request, response)
{
    user.add(request.body, function(err, count)
    {
        if(err)
        {
            response.json(err);
            console.log('add ' + err);
        }
        else
        {
            response.json(request.body);
            console.log(request.body);
        }
    });
});

router.delete('/:id',
function(request, response)
{
    user.delete(request.params.id, function(err, count)
    {
        if(err)
        {
            response.json(err);
            console.log('delete ' + err);
        }
        else 
        {
            response.json(count);
            console.log(count);
        }
    });
});

router.put('/:id',
function(request, response)
{
    user.update(request.params.id, request.body, function(err, dbResult)
    {
        if(err)
        {
            response.json(err);
            console.log('put ' + err);
        }
        else 
        {
            response.json(dbResult);
            console.log(dbResult);
        }
    });
})

module.exports = router;