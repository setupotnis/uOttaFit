import React from 'react';


 import './css/index.css';
 import'./css/App.css';
import styled from "styled-components";
import {Image, Jumbotron,Grid,Row,Button,Container} from 'react-bootstrap';
import Background from "../src/photos/person-holding-barbell-841130.jpg";

// var logoStyle = {
//     backgroundImage: "url("+ Background + ")",
//     backgroundSize:"cover", 
//     height: "100%", 
//     width: "100%", 
//     position: 'center'
// }
// var sloganStyle={}
function App() {
  return (
<<<<<<< Updated upstream
<React.Fragment>
 <div className="App">
     <header>

     </header>
<div className = "App-body">
<Container fluid={true}>

      
            <div className="row" style={{fontFamily:"Montserrat", fontWeight:'bold', fontSize: "100px", color: "white"}}>
                uOttaFit
            </div>
            <div className='row' style={{fontFamily:"Montserrat", fontWeight:'bold', fontSize: "50px", color: "white"}}>
                Lift strong lift safe<div></div>

            </div>
     
        
        </Container>

        </div>
=======

 <div className="App" style={{backgroundSize:"fill"}}src={require("./photos/person-holding-barbell-841130.jpg")}>
   
       <h3>Lift stong</h3>
        <h3>Lift safe</h3>
      
 
>>>>>>> Stashed changes
</div>

</React.Fragment>
      
  );
}

export default App;
