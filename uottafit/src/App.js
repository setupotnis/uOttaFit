import React from 'react';
// import logo from './logo.svg';

 import './css/index.css';
 import './css/animate.css';
 import './css/slicknav.css';
 import './css/bootstrap.min.css';
//  import css from './css/gijgo.css';
//  import './css/owl-carousel.min.css';
 import './css/theme-default.css';
//  import css from './css/font-awesome.min.css';

function App() {
  return (
<React.Fragment>
 <div className="App">
    <div style ={{backgroundColor: "blue", backgroundSize:"cover", fill:"100%", hight:'fill'}}>
    <div className="header-area ">
            <div id="sticky-header" className="main-header-area">
                <div className="container-fluid ">
                    <div className="header_bottom_border">
                        <div className="row align-items-center">
                            <div className="col-xl-3 col-lg-2">
                                <div className="logo">
                                    <a href="index.html">
                                        <h1 styles={{fontFamily: "Montserrat,sansSerif"}, {color: "red"}}>uOttaFit</h1>
                                    </a>
                                </div>
                            </div>
                            <div className="col-xl-6 col-lg-7">
                                <div className="main-menu  d-none d-lg-block">
                                    <nav>
                                    </nav>
                                </div>
                            </div>
                            <div className="col-xl-3 col-lg-3 d-none d-lg-block">
                                <div className="Appointment">
                                    <div className="book_btn d-none d-lg-block">
                                    </div>
                                </div>
                            </div>
                            <div className="col-12">
                                <div className="mobile_menu d-block d-lg-none"></div>
                            </div>
                        </div>
                    </div>

                </div>
            </div>
        </div>
  
  
    <div className="slider_area">
        <div className="slider_active owl-carousel">
            <div className="single_slider  d-flex align-items-center slider_bg_1 overlay">
                <div className="container">
                    <div className="row align-items-center justify-content-center">
                        <div className="col-xl-12">
                            <div className="slider_text text-center">
                                <h3>lift strong</h3>
                                <h3>lift safe</h3>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <div className="single_slider  d-flex align-items-center slider_bg_2 overlay">
                <div className="container">
                    <div className="row align-items-center justify-content-center">
                        <div className="col-xl-12">
                            <div className="slider_text text-center">
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <div className="single_slider  d-flex align-items-center slider_bg_1 overlay">
                <div className="container">
                    <div className="row align-items-center justify-content-center">
                        <div className="col-xl-12">
                            <div className="slider_text text-center">
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <div className="single_slider  d-flex align-items-center slider_bg_2 overlay">
                <div className="container">
                    <div className="row align-items-center justify-content-center">
                        <div className="col-xl-12">
                            <div className="slider_text text-center">
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
   



    <div className="priscing_area">
            <div className="container">
                    <div className="row">
                            <div className="col-xl-12">
                                <div className="section_title text-center mb-73">
                                    <h3>Our Pricing</h3>
                                    <p>There are many variations of passages of lorem Ipsum available, but the majority  have suffered alteration.</p>
                                </div>
                            </div>
                        </div>
                <div className="row">
                    <div className="col-lg-4 col-md-6">
                        <div className="single_prising text-center">
                            <div className="prising_header">
                                    <h3>Bench</h3>
                                    <span>$45/m</span>
                            </div>
                            <div className="pricing_body">
                                <ul>
                                    <li>24h unlimited access</li>
                                    <li>Trainer Advice</li>
                                    <li className="off-color">Locker + Bathroom</li>
                                    <li className="off-color">Personal trainer</li>
                                </ul>
                            </div>
                            <div className="pricing_btn">
                                    <a href="#" className="boxed-btn3">Join Now</a>
                            </div>
                        </div>
                    </div>
                    <div className="col-lg-4 col-md-6">
                        <div className="single_prising text-center">
                            <div className="prising_header">
                                    <h3>Deadlift</h3>
                                    <span>$45/m</span>
                            </div>
                            <div className="pricing_body">
                                <ul>
                                    <li>24h unlimited access</li>
                                    <li>Trainer Advice</li>
                                    <li className="off-color">Locker + Bathroom</li>
                                    <li className="off-color">Personal trainer</li>
                                </ul>
                            </div>
                            <div className="pricing_btn">
                                    <a href="#" className="boxed-btn3">Join Now</a>
                            </div>
                        </div>
                    </div>
                    <div className="col-lg-4 col-md-6">
                        <div className="single_prising text-center">
                            <div className="prising_header">
                                    <h3>Squats</h3>
                                    <span>$45/m</span>
                            </div>
                            <div className="pricing_body">
                                <ul>
                                    <li>24h unlimited access</li>
                                    <li>Trainer Advice</li>
                                    <li className="off-color">Locker + Bathroom</li>
                                    <li className="off-color">Personal trainer</li>
                                </ul>
                            </div>
                            <div className="pricing_btn">
                                    <a href="#" className="boxed-btn3">Join Now</a>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>

</div>
      </div>
      </React.Fragment>
  );
}

export default App;
