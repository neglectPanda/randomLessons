import React from "react";
import './page.css';
import Link from "next/link";
import './globals.css';

//first year

export default function Home() {
  return (
    <div className="home">
      <h1>CPE Lab Exercises <i>(web-dev-ified)</i></h1>
      <p className="description">This contains all of my CPE Lab programming basics but this time, it includes web-dev</p>

      <div className="btn">
        <Link href="/firstSem">
          <button type="button">
            <h1>First Semester</h1>
          </button>
        </Link>
        <Link href="/nowhere">
          <button type="button">
            <h1>Second Semester</h1>
          </button>
        </Link>
      </div>
    </div>
  );
}
