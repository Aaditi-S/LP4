// SPDX-License-Identifier: GPL-3.0
pragma solidity >= 0.7.0 < 0.9.0;
import "hardhat/console.log";

contract Bank{

    mapping(address => uint256) balances;

    function deposit() public payable{
        balances[msg.sender] += msg.value;
    }

    function withdraw(uint256 _amount) public{
        require(balances[msg.sender] >= _amount , "Not enough ether");
        balances[msg.sender] -= _amount;
        (bool sent ,) = msg.sender.call{value : _amount}("Sent");
        require(sent , "Failed to sent ether");
    }
    function getbalance() view returns (uint256)
    {
        return address(this).balance;
    }
}