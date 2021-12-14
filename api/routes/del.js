const express = require('express');
const router = express.Router();

const del = require('../models/del_model');

router.post('/',
function(request, response)
{
    del.del(request.body, function(err, dbResult)
    {
        if(err)
        {
            response.json(err);
        }
        else
        {
            response.json(dbResult.affectedRows);
            if(dbResult.affectedRows == 0)
            {
                console.log("Jotain meni vikaan");
            }
            else
            {
                console.log("Yhteys poistettu");
            }
        }
    });
});

module.exports = router;