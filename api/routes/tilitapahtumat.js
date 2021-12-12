const express = require('express');
const router = express.Router();
const tilitapahtumat = require('../models/tilitapahtumat_model');

router.get('/:id?',
function(request, response)
{
    if(request.params.id)
    {
        tilitapahtumat.getById(request.params.id, function(err, dbResult)
        {
            if(err)
            {
                response.json(err);
            }
            else
            {
                response.json(dbResult[0]);
            }
        });
    }
    else
    {
        response.json("Virheellinen syote");
    }
});

module.exports = router;