function [ dialedWave ] = dial_digit(dialKey, time, samplingFreq)
% Returns a wave of the dialed digit
% dialKey can be { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '#'}
% time can be (0, ... , infinite) in seconds
	
	% Setup Frequency Matrix
	freqRow = [697 770 852 941];
	freqCol = [1209 1336 1477];

	% Get Frequency Location of dialedNumber
	switch dialKey
		case '1'
			row = 1;
			col = 1;
		case '2'
			row = 1;
			col = 2;
		case '3'
			row = 1;
			col = 3;
		case '4'
			row = 2;
			col = 1;
		case '5'
			row = 2;
			col = 2;
		case '6'
			row = 2;
			col = 3;
		case '7'
			row = 3;
			col = 1;
		case '8'
			row = 3;
			col = 2;
		case '9'
			row = 3;
			col = 3;
		case '*'
			row = 4;
			col = 1;
		case '0'
			row = 4;
			col = 2;
		case '#'
			row = 4;
			col = 3;
		otherwise
			disp('Please enter a valid dial key.')
			return;
	end
	
	% Create time interval from 0 to time
	t = 0 : 1/samplingFreq : time;
	
	% Calculate corresponding row and column waves
	rowWave = sin(2 * pi * freqRow(row) * t);
	colWave = sin(2 * pi * freqCol(col) * t);
	
	% Calculate final wave
	dialedWave = (rowWave + colWave) / 2;
	return;
end

