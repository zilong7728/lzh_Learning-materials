library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Segment_Displays is port 
(
	clk, rst		: in 	std_logic;
	switch_input	: in 	std_logic_vector(3 downto 0);
	seg_sel			: out 	std_logic_vector(3 downto 0);
	seg_output		: out	std_logic_vector(7 downto 0)
);
end Segment_Displays;

architecture Behavioral of Segment_Displays is
	component clk_wiz is port
	(
		clk_in1			: in	std_logic;
		clk_out1		: out	std_logic
	);
	end component;
	component decoder is port
	(
		clk, rst		: in 	std_logic;
		switch_input	: in 	std_logic_vector(3 downto 0);
		seg_sel_d		: out 	std_logic_vector(3 downto 0);
		seg_output_d	: out 	std_logic_vector(7 downto 0)
	);
	end component;
	
	signal clk_8MHz 		: std_logic;
	
begin
	C0: clk_wiz port map(	
							clk_in1		=>	clk, 
							clk_out1	=>	clk_8MHz
						);
	C1: decoder port map(
							clk 		=> clk_8MHz,
							rst			=> rst,
							switch_input=> switch_input,
							seg_sel_d	=> seg_sel,
							seg_output_d=> seg_output
						);
	
end Behavioral;
