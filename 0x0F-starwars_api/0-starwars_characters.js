#!/usr/bin/node


const request = require('request');
const api = 'https://swapi-api.hbtn.io/api/films/';
const film = process.argv[2];


request(api + film, (error, response, body) => {
    if (error) throw error;
    const characters = JSON.parse(body).characters;
    viewNames(characters);
});

const viewNames = (names, i = 0) => {
    if (i === names.length) return;
    request(names[i], (error, response, body) => {
	if (error) throw error;
	console.log(JSON.parse(body).name);
	viewNames(names, i + 1);
    });
};
