const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');
const basicAuth = require('express-basic-auth');




//router.use(basicAuth({users: {'testi':'testi'}}))

router.post('/',
    function(request, response)
    {
        if(request.body.username && request.body.password)
        {
            const username = request.body.username;
            const password = request.body.password;
            
            console.log(password);
            login.checkPassword(username, function(dbError, dbResult)
            {
                if(dbError)
                {
                    response.json(dbError);
                    console.log(dbError);
                }
                else
                {
                    if(dbResult.length > 0)
                    {
                        // bcrypt.compare(password, dbResult[0].pin, function(err, compareResult)
                        // {
                        //     if(compareResult)
                        //     {
                        //         console.log(compareResult);
                        //         console.log("Success!");
                        //         response.send(true);
                        //     }
                        //     else
                        //     {
                        //         console.log(compareResult);
                        //         console.log(err);
                        //         console.log("Wrong Password! Your password was: " + password + " correct password is: " + dbResult[0].pin);
                        //         response.send(false);
                        //     }
                        // });
                        if(dbResult[0].pin == password)
                        {
                            console.log("Success!");
                            response.send(true);
                        }
                        else 
                        {
                            console.log("Wrong Password! Your password was: " + password + " correct password is: " + dbResult[0].pin);
                            response.send(false);
                        }
                    }
                    else
                    {
                        console.log("User does not exist");
                        response.send(false);
                    }
                }
            });
        }
        else 
        {
            console.log("Username or password missing");
            response.send(false);
        }
    }
);

module.exports = router;