import React from "react";
import "./css/index.css";
import "./css/App.css";
import Alert from "@material-ui/lab/Alert";
import { Button } from "@material-ui/core";
import { Container } from "react-bootstrap";
import { useState } from "react";

function AlertDialog(props) {
  return (
    <Alert severity="error">
      Connect a 3-D Camera in order to have access to full functionality
    </Alert>
  );
}
var logoStyle = {
  fontFamily:
    "font-family: Playfair 'Trebuchet MS', 'Lucida Sans Unicode', 'Lucida Grande', 'Lucida Sans', Arial, sans-serif",
  fontSize: "100px",
  color: "white",
};
var sloganStyle = {
  fontFamily:
    "font-family: Playfair 'Trebuchet MS', 'Lucida Sans Unicode', 'Lucida Grande', 'Lucida Sans', Arial, sans-serif",
  fontWeight: "bold",
  fontSize: "50px",
  color: "white",
};
var fillPage = {
  position: "absolute",
  top: 0,
  left: 0,
  height: "100%",
  width: "100%",
};
// function runPyScript() {
//   var jqXHR = $.ajax({
//     type: "POST",
//     url: "./test.py",
//     async: false,
//   });
//   return jqXHR.responseText;
// }
export default function App() {
  const [error, setError] = useState(false);
  const handleClick = () => {
    if (!error) setError(true);
  };
  return (
    <>
      <div className="App">
        <header className="App-header">{/* <div>uOttaHack3</div> */}</header>
        <body className="App-body" style={fillPage}>
          {error && <AlertDialog />}
          <Container>
            <div className="row" style={logoStyle}>
              uOttaFit
            </div>
            <div className="row" style={sloganStyle}>
              Lift Strong. Lift Safe.
            </div>
            <div className="grid-container grid-container--fit">
              <div className="row">
                <div className="col exercise">
                  <Button
                    variant="text"
                    color="white"
                    size="large"
                    onClick={handleClick}
                  >
                    Deadlift
                  </Button>
                </div>
                <div className="col exercise">
                  <Button
                    variant="text"
                    color="white"
                    size="large"
                    onClick={handleClick}
                  >
                    Benchpress
                  </Button>
                </div>
                <div className="col exercise">
                  <Button
                    variant="text"
                    color="white"
                    size="large"
                    onClick={handleClick}
                  >
                    Squat
                  </Button>
                </div>
              </div>
            </div>
          </Container>
        </body>
      </div>
    </>
  );
}
