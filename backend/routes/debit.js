const express = require('express');
const router = express.Router();
const debit = require('../models/debit_model');

router.get('/',
    function (request, response) {
        debit.getAll(function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                console.log(dbResult);
                response.json(dbResult);
            }
        })
    });
router.get('/:user',
    function (request, response) {
        debit.getByUsername(request.params.user, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult);
            }
        })
    });
router.post('/', 
function(request, response) {
  debit.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});
router.delete('/:id', 
function(request, response) {
  debit.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});
router.put('/:user', 
function(request, response) {
  debit.updateByUsername(request.params.user, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});
router.put('/:id', 
function(request, response) {
  debit.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});
module.exports = router;