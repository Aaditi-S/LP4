// SPDX-License-Identifier: GPL-3.0
pragma solidity>=0.7.0 < 0.9.0;
import "hardhat/console.log";

contract MarksManagement{
    struct student{
        uint256 roll;
        string fname;
        string lname;
        uint marks;
    }
    mapping(uint256 => student) studentRecord;
    address owner;
    uint256 studentCount;

    constructor(){
        owner = msg.sender;
    }

    modifier onlyOwner() {
        require(owner == msg.sender);
        _;
    }

    function addNewRecords(
        uint256 _ID,
        string memory fname,
        string memory lname,
        uint256 _marks
    )public onlyOwner {
        studentCount = studentCount+1;
        studentRecord[studentCount] = student(_ID , _fName , _lName , _marks);
    }

    fallback() external{
        console.log("fallback function called");
    }
}