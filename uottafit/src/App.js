import React from 'react';


 import './css/index.css';
import styled from "styled-components";
import {Image} from 'react-bootstrap';
import Background from "../src/photos/person-holding-barbell-841130.jpg";

function App() {
  return (

 <div className="App">
        <div style={{backgroundImage: "url("+ Background + ")", backgroundSize:"cover", height: "100%", width: "100%", position: 'center'}}>
            <div className="logo" style={{fontFamily:"Montserrat", fontWeight:'bold', fontSize: "250px", color: "white"}}>
                uOttaFit
            </div>
            <div className='slogan'>

            </div>
        </div>
</div>
    
      
  );
}

export default App;
