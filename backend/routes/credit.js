const express = require('express');
const router = express.Router();
const credit = require('../models/credit_model');

router.get('/',
    function (request, response) {
        credit.getAll(function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                console.log(dbResult);
                response.json(dbResult);
            }
        })
    });
router.get('/:id',
    function (request, response) {
        credit.getById(request.params.id, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult);
            }
        })
    });
router.post('/', 
function(request, response) {
  credit.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});
router.delete('/:id', 
function(request, response) {
  credit.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});
router.put('/:id', 
function(request, response) {
  credit.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});
module.exports = router;