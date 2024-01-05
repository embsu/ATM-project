const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

router.post('/', 
  function(request, response) {
    if(request.body.kortin_numero && request.body.PIN){ // Tässä tarkistetaan onko kortinnumero sekä pin syötetty
      const user = request.body.kortin_numero;
      const pass = request.body.PIN;
      
        login.checkPassword(user, function(err, dbResult) { // Tässä kutsutaan login_modelin checkPasswordia
          if(err){
            response.json(err.errno);
          }
          else{
            if (dbResult.length > 0) {  // Verrataan onko dbResult pidempi kuin 0
              bcrypt.compare(pass,dbResult[0].PIN, function(err,compareResult) { // Verrataan muuttujaa pass dbResulttiin. HOX!!! PIN tulee olla hashatty että toimii!!
                if(compareResult) {                                              // Jos compare on true mennään tänne
                  console.log("succes");
                  const token = generateAccessToken({ username: user }); // generoidaan tokeni
                  response.send(token);
                }
                else {
                    console.log("wrong password");
                    response.send(false);
                    // console.log(dbResult[0].PIN); //Databasen tulos oli ihan oikein
                    //console.log(pass);            //Pass oli tallentunut ihan oikein
                    // console.log(dbResult.length);
                    //console.log(compareResult);

                }			
              }
              );
            }
            else{
              console.log("user does not exists"); // Jos dbResult ei ole suurempi kuin nolla tullaan tänne.
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("username or password missing"); // Jos useria tai salasanaa ei olla syötetty tullaan tänne
      response.send(false);
    }
  }
);

function generateAccessToken(username) {
  dotenv.config();
  return jwt.sign(username, process.env.MY_TOKEN, { expiresIn: '360s' });
}

module.exports=router;