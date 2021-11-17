const express = require('express');
const router = express.Router();
const bank = require('../models/bank_model');

router.post('/tilisiirto', function(request, response)
{
    bank.debit(request.body, function(err, dbResult)
    {
        if(err)
        {
            response.json(err);
            console.log(err);
        }
        else
        {
            response.json(dbResult.affectedRows);
            console.log(dbResult.affectedRows);
        }

    })  
});

router.post('/credit_transfer', function(request, response)
{
    bank.credit(request.body, function(err, dbResult)
    {
        if(err)
        {
            response.json(err);
            console.log(err);
        }
        else
        {
            response.json(dbResult, affectedRows);
            console.log(dbResult.affectedRows);
        }
    })
});

module.exports = router;