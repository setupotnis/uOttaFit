import React from 'react';


 import './css/index.css';
import styled from "styled-components";
import Background from "./photos/back.jpg";
import {Image} from 'react-bootstrap';
const Styles = styled.div `
.Image{
    height: 100vh;
   
    background-repeat: no-repeat;
    background-size: fill;
    height:100%;
    width:100%;
}
`


function App() {
  return (

 <div className="App"><Image src={require("./photos/back.jpg")}></Image>
</div>
    
      
  );
}

export default App;
