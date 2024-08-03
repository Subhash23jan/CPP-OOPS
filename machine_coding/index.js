const express=require('express');
const app=express();
const bodyParser=require('body-parser');
const http=require('http');
const fs=require('fs');

const port=3000;
const server=http.createServer(app);


app.listen(port,()=>{
    console.log(`Server is running on port ${port}`);}
);


app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended:true}));

app.post('/api/add-log',(req,res)=>{
    const data=req.body;
    fs.appendFile('log.txt',JSON.stringify(data),(err)=>{
        if(err){
            console.log(err);
        }
        console.log('Data saved successfully');
    });
    res.send('Data saved successfully');
});
app.get('/api/get-log',(req,res)=>{
    
});