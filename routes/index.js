if (process.env.NODE_ENV !== 'production') {
    require('dotenv').config()
}

const express = require('express')
const router = express.Router()

let soilData

router.get('/', (req, res) => {
    try {
        if(soilData != null && soilData != '') {
            res.render('soil/index', {
                soilData : soilData,
                apiURL: process.env.API_URL
            })
        } else {
            res.render('soil/index', {
                soilData : 0,
                apiURL: process.env.API_URL
            })
        }
    } catch {
        res.send('There was an error')
    }
})

router.get('/soildata', (req, res) => {
    console.log(soilData)
    res.send(soilData)
})

router.get('/update/:soilReading', (req, res) => {
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