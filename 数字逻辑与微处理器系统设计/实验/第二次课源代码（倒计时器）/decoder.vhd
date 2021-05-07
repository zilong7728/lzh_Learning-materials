library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
entity decoder is port
(
	clk, rst		: in 	std_logic;
	switch_input	: in 	std_logic_vector(3 downto 0);
	seg_sel_d		: out 	std_logic_vector(3 downto 0);
	seg_output_d	: out 	std_logic_vector(7 downto 0)
);
end decoder;

architecture Behavioral of decoder is
	signal seg_sel		: std_logic_vector(3 downto 0);
	signal seg_sel_mem	: std_logic_vector(3 downto 0) := (others => '0');
	signal switch_in_d	: std_logic_vector(3 downto 0);
	signal switch_mem	: std_logic_vector(3 downto 0) := (others => '0');
	signal seg_output	: std_logic_vector(7 downto 0);
	signal seg_mem		: std_logic_vector(7 downto 0) := (others => '0');
	signal count 		: std_logic_vector(12 downto 0) := (others => '0');
	signal output_sel 	: std_logic;
begin
		
	process(clk, rst)
	begin
		if rst = '1' then
			switch_mem <= (others => '0');
		else
			if rising_edge(clk) then
				switch_mem <= switch_input;
			end if;
		end if;
	end process;
	switch_in_d <= switch_mem;
	
	process(clk, rst)
	begin
		if rst = '1' then
			count <= (others => '0');
		else
			if rising_edge(clk) then
				if	 count = "1001110000111" then			--4999
					count <= (others => '0');
				else
					count <= count + (X"000" & '1');
				end if;
				
			end if;
		end if;
	end process;
	
	process(count)
	begin
		if count < "0100111000100" then		--2500
			output_sel <= '0';
			seg_sel <= "1110";
		else
			output_sel <= '1';
			seg_sel <= "1101";
		end if;
	end process;

	process(clk, rst)
	begin
		if rst = '1' then
			seg_sel_mem <= (others => '0');
		else
			if rising_edge(clk) then
				seg_sel_mem <= seg_sel;
			end if;
		end if;
	end process;
	seg_sel_d <= seg_sel_mem;
	
	process(switch_in_d, output_sel)
	begin
		if output_sel = '0' then
			case switch_in_d is
				when "0000" => seg_output <= "00000011";
				when "0001" => seg_output <= "10011111";
				when "0010" => seg_output <= "00100101";
				when "0011" => seg_output <= "00001101";
				when "0100" => seg_output <= "10011001";
				when "0101" => seg_output <= "01001001";
				when "0110" => seg_output <= "01000001";
				when "0111" => seg_output <= "00011111";
				when "1000" => seg_output <= "00000001";
				when "1001" => seg_output <= "00001001";
				when "1010" => seg_output <= "00000011";
				when "1011" => seg_output <= "10011111";
				when "1100" => seg_output <= "00100101";
				when "1101" => seg_output <= "00001101";
				when "1110" => seg_output <= "10011001";
				when others => seg_output <= "01001001";
			end case;
		else
			case switch_in_d is
				when "0000" => seg_output <= "00000011";
				when "0001" => seg_output <= "00000011";
				when "0010" => seg_output <= "00000011";
				when "0011" => seg_output <= "00000011";
				when "0100" => seg_output <= "00000011";
				when "0101" => seg_output <= "00000011";
				when "0110" => seg_output <= "00000011";
				when "0111" => seg_output <= "00000011";
				when "1000" => seg_output <= "00000011";
				when "1001" => seg_output <= "00000011";
				when "1010" => seg_output <= "10011111";
				when "1011" => seg_output <= "10011111";
				when "1100" => seg_output <= "10011111";
				when "1101" => seg_output <= "10011111";
				when "1110" => seg_output <= "10011111";
				when others => seg_output <= "10011111";
			end case;
		end if;
	end process;
	
	process(clk, rst)
	begin
		if rst = '1' then
			seg_mem <= (others => '0');
		else
			if rising_edge(clk) then
				seg_mem <= seg_output;
			end if;
		end if;
	end process;
	seg_output_d <= seg_mem;
end Behavioral;
