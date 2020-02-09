import React from 'react';
import './css/index.css';
import'./css/App.css';
import styled from "styled-components";
import {Image, Jumbotron,Grid,Row,Button,Container} from 'react-bootstrap';


var logoStyle={
    fontFamily:"font-family: Playfair 'Trebuchet MS', 'Lucida Sans Unicode', 'Lucida Grande', 'Lucida Sans', Arial, sans-serif",  
    fontSize: "100px", 
    color: "white",
}
var sloganStyle ={
    fontFamily:"font-family: Playfair 'Trebuchet MS', 'Lucida Sans Unicode', 'Lucida Grande', 'Lucida Sans', Arial, sans-serif", 
    fontWeight:'bold', 
    fontSize: "50px", 
    color: "white",
}
var fillPage ={
    position: "absolute", 
    top: 0,
    left: 0,
    height: "100%",
    width: "100%",
}
function App() {
  return (
<React.Fragment>
 <div className="App">
    <header className="App-header">
        {/* <div>uOttaHack3</div> */}
    </header>
<body className = "App-body" style={fillPage}>
<Container >
            <div className="row" style={logoStyle}>
                uOttaFit
            </div>
            <div className='row' style={sloganStyle}>
                Lift Strong. Lift Safe.
            </div>
            <div className='row'>
                <div className="col exercise" >
                    <div>
                        <p>Deadlift</p>
                    </div>
                </div>
                <div className="col exercise">
                    <div>
                        <p>Benchpress</p></div>
                    </div>
                <div className="col exercise">
                    <div>
                        <p>Squat</p>
                    </div>
                </div>
            </div>
        </Container>
    </body>
</div>

</React.Fragment>
      
  );
}

export default App;
