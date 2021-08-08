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

router.get('/:data', (req, res) => {
    try {
        if(req.params.data != null && req.params.data != '') {
            soilData = req.params.data
        } else {
            soilData = 0
        }
    } catch {
        res.send('There was an error')
    }
})

module.exports = router