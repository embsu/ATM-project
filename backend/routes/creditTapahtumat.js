const express = require('express');
const router = express.Router();
const tapahtumat = require('../models/creditTapahtumat_model');

router.get('/',
    function (request, response) {
        tapahtumat.getAll(function (err, dbResult) {
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
        tapahtumat.getById(request.params.id, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult);
            }
        })
    });
router.post('/', 
function(request, response) {
  tapahtumat.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});
router.delete('/:id', 
function(request, response) {
  tapahtumat.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});
router.put('/:id', 
function(request, response) {
  tapahtumat.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});
module.exports = router;
