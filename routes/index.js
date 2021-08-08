const express = require('express')
const router = express.Router()

let soilData

router.get('/', (req, res) => {
    try {
        if(soilData != null && soilData != '') {
            res.render('soil/index', {
                soilData : soilData
            })
        } else {
            res.render('soil/index', {
                soilData : 0
            })
        }
    } catch {
        res.send('There was an error')
    }
})

router.get('/soildata', (req, res) => {
    res.send(soilData);
})

router.get('/:soilReading', (req, res) => {
    try {
        if(req.params.soilReading != null && req.params.soilReading != '') {
            soilData = req.params.soilReading
            res.send('OK')
        } else {
            soilData = 0
            res.send('No Value')
        }
    } catch {
        res.send('There was an error')
    }
})

module.exports = router