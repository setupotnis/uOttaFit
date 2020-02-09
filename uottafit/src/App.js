import React,{Component} from 'react';
import './css/index.css';
import'./css/App.css';
import {Image, Jumbotron,Grid,Row,Button,Container} from 'react-bootstrap';
import {BrowserRouter as Router, Route, Switch,Link,Redirect  } from "react-router-dom";
import noPageFound from "./404.js";
import { render } from '@testing-library/react';
import $ from 'jquery';

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
function runPyScript(){
  var jqXHR = $.ajax({
      type: "POST",
      url: "./test.py",
      async: false,
      
  });

  return jqXHR.responseText;
}
class App extends Component {
  render(){
  return (
<React.Fragment>
 <div className="App">
    <header className="App-header">
        {/* <div>uOttaHack3</div> */}
    </header>
<body className = "App-body" style={fillPage}>
        <Container>
            <div className="row" style={logoStyle}>
                uOttaFit
            </div>
            <div className='row' style={sloganStyle}>
                Lift Strong. Lift Safe.
            </div>
            <div className='grid-container grid-container--fit'>
                <div className='row'>
                    <div className="col exercise" onClick ={runPyScript} >
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
            </div>
        </Container>
    </body>
</div>


{/* <Router>
        <Switch>
        <Route exact path="/" component = {App}/>
        <Route exact path="/App" component = {App}/>
        <Route exact path= "/404" component ={noPageFound}></Route>  
        <Redirect to ="/404"/>   
        </Switch>
      </Router> */}

</React.Fragment>

  );
  }
}

export default App;
