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
     <header className="App-header">
<div>blakd</div>
     </header>
<body className = "App-body">
<Container fluid={true}>

      
            <div className="row" style={{fontFamily:"Montserrat", fontWeight:'bold', fontSize: "100px", color: "white"}}>
                uOttaFit
            </div>
            <div className='row' style={{fontFamily:"Montserrat", fontWeight:'bold', fontSize: "50px", color: "white"}}>
                Lift Strong. Lift Safe.
                </div>

          <div className='row'>
                
                <div className="col exersice" >
                <div><p>bench</p></div>

                </div>
                <div className="col exersice">
                <div><p>bench</p></div>
                  </div>
                  <div className="col exersice">
                  <div><p>bench</p></div>
                  </div>
            
                  </div>
                  
     
        
        </Container>

        </body>
</div>

</React.Fragment>
      
  );
}

export default App;
