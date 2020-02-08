import React from 'react';


 import './css/index.css';
import styled from "styled-components";
import {Image, Jumbotron,Grid,Row,Button,Container} from 'react-bootstrap';
import Background from "../src/photos/person-holding-barbell-841130.jpg";

var logoStyle = {
    backgroundImage: "url("+ Background + ")",
    backgroundSize:"cover", 
    height: "100%", 
    width: "100%", 
    position: 'center'
}
var sloganStyle={}
function App() {
  return (
<React.Fragment>
 <div className="App">
     <header>

     </header>
<body>
<Container fluid={true}>

      
            <div className="logo" style={{fontFamily:"Montserrat", fontWeight:'bold', fontSize: "250px", color: "white"}}>
                uOttaFit
            </div>
            <div className='row' style={{fontFamily:"Montserrat", fontWeight:'bold', fontSize: "250px", color: "white"}}>
                Lift strong lift safe

            </div>
            <div className = 'row'> blada</div>
            <div className = 'row'> afds</div>
            <div className = 'row'> daf</div>
            <div className = 'row'>fasdf </div>
            <div className = 'row'>adfasdf </div>
            <div className = 'row'> afasdfa</div>
        
        </Container>

        </body>
</div>

</React.Fragment>
      
  );
}

export default App;
