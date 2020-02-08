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
</div>

</React.Fragment>
      
  );
}

export default App;
