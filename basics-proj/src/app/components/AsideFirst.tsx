import React from 'react'
import './AsideFirst.css'

const AsideFirst = () => {
  return (
    <aside>
        <h1>First Semester</h1>
        <hr />
        <div className="side-btn-container">
            <table className="side-nav">
                <tbody>   
                    <tr>
                        <td>
                            <button className="nav-btn" type="button">
                                <h3>Arithmetic Operators</h3>
                                <h3 className="caret-symbol">ˇ</h3>
                            </button>   
                        </td>      
                    </tr>
                    <tr>
                        <td>
                            <button className="nav-btn" type="button">
                                <h3>Selection Structure</h3>
                                <h3 className="caret-symbol">ˇ</h3>
                            </button>       
                        </td>      
                    </tr>
                    <tr>
                        <td>
                            <button className="nav-btn" type="button">
                                <h3>Simple Repetition</h3>
                                <h3 className="caret-symbol">ˇ</h3>
                            </button> 
                        </td>        
                    </tr>
                    <tr>
                        <td>
                            <button className="nav-btn" type="button">
                                <h3>Advanced Repetition</h3>
                                <h3 className="caret-symbol">ˇ</h3>
                            </button>
                        </td>         
                    </tr>
                    <tr>
                        <td>
                            <button className="nav-btn" type="button">
                                <h3>Modularization</h3>
                                <h3 className="caret-symbol">ˇ</h3>
                            </button>    
                        </td>         
                    </tr>
                    <tr>
                        <td>
                            <button className="nav-btn" type="button">
                                <h3>Arrays & Strings</h3>
                                <h3 className="caret-symbol">ˇ</h3>
                            </button>     
                        </td>        
                    </tr>
                    <tr>
                        <td>
                            <button className="nav-btn" type="button">
                                <h3>Pointers</h3>
                                <h3 className="caret-symbol">ˇ</h3>
                            </button>  
                        </td>       
                    </tr>
                    <tr>
                        <td>
                            <button className="nav-btn" type="button">
                                <h3>File Handling</h3>
                                <h3 className="caret-symbol">ˇ</h3>
                            </button>    
                        </td>         
                    </tr>
                </tbody>
            </table>
        </div>
    </aside>
  )
}

export default AsideFirst