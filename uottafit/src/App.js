import React from 'react';


 import './css/index.css';
import styled from "styled-components";
import Background from "./photos/back.jpg";
import {Image} from 'react-bootstrap';

function App() {
  return (

 <div className="App">
     <img style={{backgroundSize:"fill"}}src={require("./photos/person-holding-barbell-841130.jpg")}></img>
</div>
    
      
  );
}

export default App;
