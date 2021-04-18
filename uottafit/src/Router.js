import React, { Component } from "react";

import {
  BrowserRouter as Router,
  Route,
  Switch,
  Link,
  Redirect,
} from "react-router-dom";
import App from "./App";
import Nopagefound from "./Pages/404";

class Router extends Component {
  render() {
    return (
      <React.Fragment>
        <Router>
          <Switch>
            <Route exact path="/" component={noPageFound} />
            <Route exact path="/App" component={App} />
            <Route exact path="/404" component={noPageFound} />
            <Redirect to="/404" />
          </Switch>
        </Router>
      </React.Fragment>
    );
  }
}
export default App;
