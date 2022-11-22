pragma solidity >=0.7.0 < 0.9.0;
import "hardhat/console.sol";

contract Bank{

    mapping(address => uint256) balances;

    function deposit() public payable{
        balances[msg.sender] += msg.value;
    }

    function withdraw(uint256 _amount)public{
        require(balances[msg.sender] >= _amount , "No enough ether");
        balances[msg.sender] -= _amount;
        (bool sent ,) = msg.sender.call{value : _amount}("Sent");
        require(sent , "failed to send ether");
    }
    function getbalance() view public returns (uint256)
    {
        return address(this).balance;
    }
}